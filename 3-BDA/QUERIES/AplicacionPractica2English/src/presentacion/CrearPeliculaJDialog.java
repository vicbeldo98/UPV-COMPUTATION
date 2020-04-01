package presentacion;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import java.awt.GridBagLayout;

import javax.swing.JLabel;

import java.awt.GridBagConstraints;

import javax.swing.JTextField;

import java.awt.Insets;

import javax.swing.JOptionPane;


import javax.swing.JComboBox;

import comunicacion.LibroDTO;
import comunicacion.PeliculaDTO;

import excepciones.LogicaExcepcion;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowEvent;
import java.util.List;

import logica.Controlador;
import java.awt.event.WindowAdapter;


public class CrearPeliculaJDialog extends JDialog {
	
	private static final long serialVersionUID = 1L;
	private final JPanel contentPanel = new JPanel();
	private JTextField textFieldCodigo;
	private JTextField textFieldTitulo;
	private JTextField textFieldDirector;
	private JTextField textFieldDuracion;
	private JTextField textFieldAnyo;
	
	private JComboBox<LibroDTO> comboBoxLibro;
	private Controlador control;

	public int showDialog() {
		
		setResizable(false);		
		setModal(true);
	    setVisible(true);
	    return 0;
	}

	/**
	 * Create the dialog.
	 */
	public CrearPeliculaJDialog(Controlador c) {
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent arg0) {
				do_this_windowClosing(arg0);
			}
		});
		this.control=c;
		setTitle("New Movie");
		setBounds(100, 100, 576, 345);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.WEST);
		GridBagLayout gbl_contentPanel = new GridBagLayout();
		gbl_contentPanel.columnWidths = new int[]{82, 208, 115, 0, 0};
		gbl_contentPanel.rowHeights = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		gbl_contentPanel.columnWeights = new double[]{0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		gbl_contentPanel.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		contentPanel.setLayout(gbl_contentPanel);
		{
			JLabel lblCodigo = new JLabel("Code:");
			GridBagConstraints gbc_lblCodigo = new GridBagConstraints();
			gbc_lblCodigo.insets = new Insets(0, 0, 5, 5);
			gbc_lblCodigo.anchor = GridBagConstraints.EAST;
			gbc_lblCodigo.gridx = 0;
			gbc_lblCodigo.gridy = 0;
			contentPanel.add(lblCodigo, gbc_lblCodigo);
		}
		{
			textFieldCodigo = new JTextField();
			GridBagConstraints gbc_textFieldCodigo = new GridBagConstraints();
			gbc_textFieldCodigo.anchor = GridBagConstraints.WEST;
			gbc_textFieldCodigo.insets = new Insets(0, 0, 5, 5);
			gbc_textFieldCodigo.gridx = 1;
			gbc_textFieldCodigo.gridy = 0;
			contentPanel.add(textFieldCodigo, gbc_textFieldCodigo);
			textFieldCodigo.setColumns(10);
		}
		{
			JLabel lblDireccion = new JLabel("Title:");
			GridBagConstraints gbc_lblDireccion = new GridBagConstraints();
			gbc_lblDireccion.anchor = GridBagConstraints.EAST;
			gbc_lblDireccion.insets = new Insets(0, 0, 5, 5);
			gbc_lblDireccion.gridx = 0;
			gbc_lblDireccion.gridy = 1;
			contentPanel.add(lblDireccion, gbc_lblDireccion);
		}
		{
			textFieldTitulo = new JTextField();
			GridBagConstraints gbc_textFieldDireccion = new GridBagConstraints();
			gbc_textFieldDireccion.gridwidth = 2;
			gbc_textFieldDireccion.fill = GridBagConstraints.HORIZONTAL;
			gbc_textFieldDireccion.insets = new Insets(0, 0, 5, 5);
			gbc_textFieldDireccion.gridx = 1;
			gbc_textFieldDireccion.gridy = 1;
			contentPanel.add(textFieldTitulo, gbc_textFieldDireccion);
			textFieldTitulo.setColumns(10);
		}
		{
			JLabel lblLocalidad = new JLabel("Year:");
			GridBagConstraints gbc_lblLocalidad = new GridBagConstraints();
			gbc_lblLocalidad.anchor = GridBagConstraints.EAST;
			gbc_lblLocalidad.insets = new Insets(0, 0, 5, 5);
			gbc_lblLocalidad.gridx = 0;
			gbc_lblLocalidad.gridy = 2;
			contentPanel.add(lblLocalidad, gbc_lblLocalidad);
		}
		{
			textFieldAnyo = new JTextField();
			GridBagConstraints gbc_textFieldSuperficie = new GridBagConstraints();
			gbc_textFieldSuperficie.anchor = GridBagConstraints.WEST;
			gbc_textFieldSuperficie.insets = new Insets(0, 0, 5, 5);
			gbc_textFieldSuperficie.gridx = 1;
			gbc_textFieldSuperficie.gridy = 2;
			contentPanel.add(textFieldAnyo, gbc_textFieldSuperficie);
			textFieldAnyo.setColumns(10);
		}
		{
			JLabel lblFecha = new JLabel("Length:");
			GridBagConstraints gbc_lblFecha = new GridBagConstraints();
			gbc_lblFecha.anchor = GridBagConstraints.EAST;
			gbc_lblFecha.insets = new Insets(0, 0, 5, 5);
			gbc_lblFecha.gridx = 0;
			gbc_lblFecha.gridy = 3;
			contentPanel.add(lblFecha, gbc_lblFecha);
		}
		{
			textFieldDuracion = new JTextField();
			GridBagConstraints gbc_textFieldFecha = new GridBagConstraints();
			gbc_textFieldFecha.anchor = GridBagConstraints.WEST;
			gbc_textFieldFecha.insets = new Insets(0, 0, 5, 5);
			gbc_textFieldFecha.gridx = 1;
			gbc_textFieldFecha.gridy = 3;
			contentPanel.add(textFieldDuracion, gbc_textFieldFecha);
			textFieldDuracion.setColumns(10);
		}
		{
			JLabel lblSuperficie = new JLabel("Director:");
			GridBagConstraints gbc_lblSuperficie = new GridBagConstraints();
			gbc_lblSuperficie.anchor = GridBagConstraints.EAST;
			gbc_lblSuperficie.insets = new Insets(0, 0, 5, 5);
			gbc_lblSuperficie.gridx = 0;
			gbc_lblSuperficie.gridy = 4;
			contentPanel.add(lblSuperficie, gbc_lblSuperficie);
		}
//		{
//			try{
//			List<Cliente> lcli ;//= control.encontrarClientes();
//			for(Cliente cl:lcli){
//				comboBoxPropietario.addItem(cl);
//			}
//			}
//			catch(LogicaExcepcion e){
//				System.out.println("DAOException "+e);
//			}
//		}
		{
			textFieldDirector = new JTextField();
			GridBagConstraints gbc_textFieldLocalidad = new GridBagConstraints();
			gbc_textFieldLocalidad.insets = new Insets(0, 0, 5, 5);
			gbc_textFieldLocalidad.fill = GridBagConstraints.HORIZONTAL;
			gbc_textFieldLocalidad.gridwidth = 2;
			gbc_textFieldLocalidad.gridx = 1;
			gbc_textFieldLocalidad.gridy = 4;
			contentPanel.add(textFieldDirector, gbc_textFieldLocalidad);
			textFieldDirector.setColumns(10);
		}
		{
			JLabel lblAsesor = new JLabel("Book:");
			GridBagConstraints gbc_lblAsesor = new GridBagConstraints();
			gbc_lblAsesor.anchor = GridBagConstraints.EAST;
			gbc_lblAsesor.insets = new Insets(0, 0, 5, 5);
			gbc_lblAsesor.gridx = 0;
			gbc_lblAsesor.gridy = 5;
			contentPanel.add(lblAsesor, gbc_lblAsesor);
		}
		comboBoxLibro = new JComboBox<LibroDTO>();
		GridBagConstraints gbc_comboBoxAsesor = new GridBagConstraints();
		gbc_comboBoxAsesor.insets = new Insets(0, 0, 5, 5);
		gbc_comboBoxAsesor.fill = GridBagConstraints.HORIZONTAL;
		gbc_comboBoxAsesor.gridx = 1;
		gbc_comboBoxAsesor.gridy = 5;
		contentPanel.add(comboBoxLibro, gbc_comboBoxAsesor);
		{
			JLabel lblPropietario = new JLabel("");
			GridBagConstraints gbc_lblPropietario = new GridBagConstraints();
			gbc_lblPropietario.anchor = GridBagConstraints.EAST;
			gbc_lblPropietario.insets = new Insets(0, 0, 0, 5);
			gbc_lblPropietario.gridx = 1;
			gbc_lblPropietario.gridy = 9;
			contentPanel.add(lblPropietario, gbc_lblPropietario);
		}
		{
			try{
				List<LibroDTO> listaLibros = control.buscarLibros();
				comboBoxLibro.addItem(null);
				for(LibroDTO libro:listaLibros){
					comboBoxLibro.addItem(libro);
				}
				}
				catch(LogicaExcepcion e){
					System.out.println("DAOException "+e);
				}
			
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton crearButton = new JButton("New");
				crearButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						crearPeliculaMenuItemActionPerformed(arg0);
					}
				});
				crearButton.setActionCommand("OK");
				buttonPane.add(crearButton);
				getRootPane().setDefaultButton(crearButton);
			}
			{
				JButton cancelarButton = new JButton("Cancel");
				cancelarButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						do_cancelarButton_actionPerformed(arg0);
					}
				});
				cancelarButton.setActionCommand("Cancel");
				buttonPane.add(cancelarButton);
			}
		}
	}

	private void crearPeliculaMenuItemActionPerformed(ActionEvent arg0){
		
		if (textFieldCodigo.getText().isEmpty()){
			JOptionPane.showMessageDialog(this, "Please, write a code.", "Error", JOptionPane.ERROR_MESSAGE);
			textFieldCodigo.grabFocus();
			return;
		}
		if (textFieldTitulo.getText().isEmpty()){
			JOptionPane.showMessageDialog(this, "Please, write a title.", "Error", JOptionPane.ERROR_MESSAGE);
			textFieldTitulo.grabFocus();
			return;
		}
		if (textFieldDuracion.getText().isEmpty()){
			JOptionPane.showMessageDialog(this, "Please, write the lenght.", "Error", JOptionPane.ERROR_MESSAGE);
			textFieldTitulo.grabFocus();
			return;
		}
		int duracion=0;
		try{
			duracion = Integer.parseInt(textFieldDuracion.getText());
			if (duracion<=0){
				JOptionPane.showMessageDialog(this, "Lenght must be greater than 0.", "Error", JOptionPane.ERROR_MESSAGE);
				textFieldDuracion.grabFocus();
				return;
			}
		}
		catch(NumberFormatException e)
		{
			JOptionPane.showMessageDialog(this, "Lenght must be a number.", "ERROR", JOptionPane.ERROR_MESSAGE);
			textFieldDuracion.grabFocus();
		}
		String anyo="";
		try{
			if (!textFieldAnyo.getText().isEmpty()) anyo = Integer.toString(Integer.parseInt(textFieldAnyo.getText()));
			else anyo = textFieldAnyo.getText();
		}
		catch(NumberFormatException e)
		{
			JOptionPane.showMessageDialog(this, "Year must be a number", "ERROR", JOptionPane.ERROR_MESSAGE);
			textFieldAnyo.grabFocus();
			return;
		}
		LibroDTO libro = (LibroDTO) comboBoxLibro.getSelectedItem();
		String codLibro=null;
		if (libro!=null) codLibro = libro.getCod_lib();
		
			
		try{
			PeliculaDTO pelicula= new PeliculaDTO(textFieldCodigo.getText(), textFieldTitulo.getText(),
					anyo, duracion, codLibro, textFieldDirector.getText());
			control.crearPelicula(pelicula);
			JOptionPane.showMessageDialog(this,"Movie created.", "Movie",JOptionPane.INFORMATION_MESSAGE);
			  
			  do_this_windowClosing(new WindowEvent(getOwner(), WindowEvent.WINDOW_CLOSING));
		}
		catch (Exception e){
			JOptionPane.showMessageDialog(this,e.getMessage(),"ERROR",JOptionPane.ERROR_MESSAGE);
		}
	}
	public void setControlador(Controlador control){
		this.control=control;
	}
	protected void do_this_windowClosing(WindowEvent arg0) {
		setVisible(false);
		dispose();
	}
	protected void do_cancelarButton_actionPerformed(ActionEvent arg0) {
		do_this_windowClosing(new WindowEvent(getOwner(), WindowEvent.WINDOW_CLOSING));
	}
}
