package presentacion;

import java.awt.BorderLayout;
import java.awt.FlowLayout;


import javax.swing.JButton;
import javax.swing.JDialog;

import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.border.EmptyBorder;
import javax.swing.JLabel;
import javax.swing.SwingConstants;
import javax.swing.JTextField;




import logica.Controlador;




import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;



public class ConnectarSistema extends JDialog {

	private static final long serialVersionUID = 1L;
	private final JPanel contentPanel = new JPanel();
	private JTextField textFieldLogin;
	private JDialog dialogo;
	private JPasswordField textFieldPassword;
	private int result;
	//****************************************************************
	//**** DEFINIMOS EL CONTROLADOR
	//****************************************************************
	
	private Controlador controlador;
	
	public int showDialog() {
		setModal(true);
	    setVisible(true);
	    return result;
	}

	/**
	 * Create the dialog.
	 */
	public ConnectarSistema(Controlador c) {
		dialogo=this;
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent arg0) {
				do_this_windowClosing(arg0);
			}
		});
		setResizable(false);
		controlador=c;
		setTitle("Connect to Server.");
		
		//this.setLocationRelativeTo(null); 
			
		setBounds(100, 100, 450, 212);
		
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		{
			JLabel label = new JLabel("User");
			label.setHorizontalAlignment(SwingConstants.RIGHT);
			label.setBounds(50, 38, 65, 14);
			contentPanel.add(label);
		}
		{
			textFieldLogin = new JTextField();
			textFieldLogin.setColumns(10);
			textFieldLogin.setBounds(125, 35, 230, 20);
			contentPanel.add(textFieldLogin);
		}
		{
			JLabel label = new JLabel("Password");
			label.setHorizontalAlignment(SwingConstants.RIGHT);
			label.setBounds(10, 83, 105, 14);
			contentPanel.add(label);
		}
		{
			textFieldPassword = new JPasswordField();
			textFieldPassword.setColumns(10);
			textFieldPassword.setBounds(125, 80, 230, 20);
			contentPanel.add(textFieldPassword);
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("OK");
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						
							 
						try{
							String contraseña = new String(textFieldPassword.getPassword());
							if (textFieldLogin.getText().isEmpty() || contraseña.isEmpty())
							{
								JOptionPane.showMessageDialog(dialogo,"Complete all the fields.", "ERROR", JOptionPane.ERROR_MESSAGE);
							}
							else
							{
							controlador.connectarDAL(textFieldLogin.getText(),	contraseña);
							  JOptionPane.showMessageDialog(dialogo,"Connected.", "Connection",JOptionPane.INFORMATION_MESSAGE);
							  result = JOptionPane.OK_OPTION;
							  do_this_windowClosing(new WindowEvent(getOwner(), WindowEvent.WINDOW_CLOSING));
							}
						}catch (Exception ex){
															
								JOptionPane.showMessageDialog(null,ex.getMessage(),"ERROR",
										JOptionPane.ERROR_MESSAGE);
								
							}
						
						}
					
					
				});
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						//Cerramos el formulario
						result = JOptionPane.CANCEL_OPTION;
						do_this_windowClosing(new WindowEvent(getOwner(), WindowEvent.WINDOW_CLOSING));
						
					}
				});
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
			}
		}
	}
	protected void do_this_windowClosing(WindowEvent arg0) {
		setVisible(false);
		dispose();
	}
}
