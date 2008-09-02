package org.eclipse.swt.tools.views;


import java.util.ArrayList;

import org.eclipse.swt.tools.internal.ASTClass;
import org.eclipse.swt.tools.internal.JNIClass;
import org.eclipse.swt.tools.internal.JNIGeneratorApp;
import org.eclipse.swt.tools.internal.MacGenerator;
import org.eclipse.swt.tools.internal.MacGeneratorUI;
import org.eclipse.swt.tools.internal.MetaData;
import org.eclipse.swt.widgets.Composite;
import org.eclipse.ui.part.*;
import org.eclipse.core.resources.IResource;
import org.eclipse.core.resources.IResourceVisitor;
import org.eclipse.core.resources.IWorkspaceRoot;
import org.eclipse.core.resources.ResourcesPlugin;
import org.eclipse.core.runtime.CoreException;
import org.eclipse.core.runtime.Path;
import org.eclipse.jface.action.*;
import org.eclipse.ui.*;


/**
 * This sample class demonstrates how to plug-in a new
 * workbench view. The view shows data obtained from the
 * model. The sample creates a dummy model on the fly,
 * but a real implementation would connect to the model
 * available either in this or another plug-in (e.g. the workspace).
 * The view is connected to the model using a content provider.
 * <p>
 * The view uses a label provider to define how model
 * objects should be presented in the view. Each
 * view can present the same model objects using
 * different labels and icons, if needed. Alternatively,
 * a single label provider can be shared between views
 * in order to ensure that objects of the same type are
 * presented in the same way everywhere.
 * <p>
 */

public class MacGeneratorView extends ViewPart {
	private Action generateAction;
	MacGeneratorUI ui;

	IResource plugin, root, pi;
	
	/**
	 * The constructor.
	 */
	public MacGeneratorView() {
		IWorkspaceRoot workspace = ResourcesPlugin.getWorkspace().getRoot();
		plugin = workspace.findMember(new Path("org.eclipse.swt"));
		root = workspace.findMember(new Path("org.eclipse.swt/Eclipse SWT PI/cocoa"));
		pi = workspace.findMember(new Path("org.eclipse.swt/Eclipse SWT PI/cocoa/org/eclipse/swt/internal/cocoa"));
	}

	/**
	 * This is a callback that will allow us
	 * to create the viewer and initialize it.
	 */
	public void createPartControl(Composite parent) {
		String[] xmls = null;
		xmls = new String[]{
			"AppKitFull.bridgesupport",
			"FoundationFull.bridgesupport",
			"WebKitFull.bridgesupport",
		};
		MacGenerator gen = new MacGenerator();
		gen.setXmls(xmls);
		gen.setOutputDir(root.getLocation().toPortableString());
		gen.setMainClass("org.eclipse.swt.internal.cocoa.OS");
		ui = new MacGeneratorUI(gen);
		ui.setActionsVisible(false);
		ui.open(parent);

		makeActions();
		contributeToActionBars();
	}

	private void contributeToActionBars() {
		IActionBars bars = getViewSite().getActionBars();
		fillLocalPullDown(bars.getMenuManager());
		fillLocalToolBar(bars.getToolBarManager());
	}

	private void fillLocalPullDown(IMenuManager manager) {
		manager.add(generateAction);
	}

	private void fillLocalToolBar(IToolBarManager manager) {
		manager.add(generateAction);
	}
	
	void refresh() {
		try {
			root.refreshLocal(IResource.DEPTH_INFINITE, null);
		} catch (CoreException e) {
//			e.printStackTrace();
		}
	}
	
	void generate() {
		ui.generate();
		refresh();
		final String mainClassName = "org.eclipse.swt.internal.cocoa.OS";
		final String mainPath = root.getLocation() + "/" + mainClassName.replace('.', '/') + ".java";
		final MetaData metaData = new MetaData(mainClassName);
		final ASTClass mainClass = new ASTClass(mainPath, metaData);
		final ArrayList classes = new ArrayList();
		try {
			pi.accept(new IResourceVisitor() {
				public boolean visit(IResource resource) throws CoreException {
					String path = resource.getLocation().toPortableString();
					if ("java".equals(resource.getFileExtension())) {
						if (mainPath.equals(path)){
							classes.add(mainClass);
						} else {
							classes.add(new ASTClass(path, metaData));
						}
						return false;
					}
					return true;
				}
			});
		} catch (CoreException e) {
//			e.printStackTrace();
		}		
		JNIGeneratorApp app = new JNIGeneratorApp();
		app.setOutputDir(root.getLocation().toPortableString() + "/library");
		app.setMetaData(metaData);
		app.setMainClass(mainClass);
		app.setGenerateMetaData(false);
		app.setClasses((JNIClass[])classes.toArray(new JNIClass[classes.size()]));
		app.generate();
		refresh();
	}

	private void makeActions() {
		generateAction = new Action() {
			public void run() {
				generate();
			}
		};
		generateAction.setText("Generate");
		generateAction.setToolTipText("Generate");
		generateAction.setImageDescriptor(PlatformUI.getWorkbench().getSharedImages().
			getImageDescriptor(ISharedImages.IMG_ETOOL_SAVE_EDIT));
	}

	/**
	 * Passing the focus request to the viewer's control.
	 */
	public void setFocus() {
		ui.setFocus();
	}
}