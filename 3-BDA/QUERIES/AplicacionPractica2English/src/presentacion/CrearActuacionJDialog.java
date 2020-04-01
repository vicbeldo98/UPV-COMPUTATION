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


import java.awt.Insets;

import javax.swing.JOptionPane;

import javax.swing.JComboBox;

import comunicacion.ActorDTO;
import comunicacion.ActuaDTO;

import comunicacion.PeliculaDTO;

import excepciones.LogicaExcepcion;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.WindowEvent;
import java.util.List;

import logica.Controlador;

import java.awt.event.WindowAdapter;


public class CrearActuacionJDialog extends JDialog {
	private static final long serialVersionUID = 1L;
	private final JPanel contentPanel = new JPanel();

	private JComboBox<PeliculaDTO> comboBoxPelicula;
	private JComboBox<ActorDTO> comboBoxActor;
	private JComboBox<String> comboBoxPapel;
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
	public CrearActuacionJDialog(Controlador c) {
		addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent arg0) {
				do_this_windowClosing(arg0);
			}
		});
		this.control=c;
		setTitle("New Performance (Act table)");
		setBounds(100, 100, 479, 345);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.WEST);
		GridBagLayout gbl_contentPanel = new GridBagLayout();
		gbl_contentPanel.columnWidths = new int[]{82, 208, 115, 0, 0};
		gbl_contentPanel.rowHeights = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		gbl_contentPanel.columnWeights = new double[]{0.0, 1.0, 0.0, 0.0, Double.MIN_VALUE};
		gbl_contentPanel.rowWeights = new double[]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, Double.MIN_VALUE};
		contentPanel.setLayout(gbl_contentPanel);
		{
			JLabel lblCodigo = new JLabel("Movie:");
			GridBagConstraints gbc_lblCodigo = new GridBagConstraints();
			gbc_lblCodigo.insets = new Insets(0, 0, 5, 5);
			gbc_lblCodigo.anchor = GridBagConstraints.EAST;
			gbc_lblCodigo.gridx = 0;
			gbc_lblCodigo.gridy = 0;
			contentPanel.add(lblCodigo, gbc_lblCodigo);
		}
		{
			comboBoxPelicula = new JComboBox<PeliculaDTO>();
			GridBagConstraints gbc_comboBox = new GridBagConstraints();
			gbc_comboBox.insets = new Insets(0, 0, 5, 5);
			gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
			gbc_comboBox.gridx = 1;
			gbc_comboBox.gridy = 0;
			contentPanel.add(comboBoxPelicula, gbc_comboBox);
		}
		{
			JLabel lblDireccion = new JLabel("Actor:");
			GridBagConstraints gbc_lblDireccion = new GridBagConstraints();
			gbc_lblDireccion.anchor = GridBagConstraints.EAST;
			gbc_lblDireccion.insets = new Insets(0, 0, 5, 5);
			gbc_lblDireccion.gridx = 0;
			gbc_lblDireccion.gridy = 1;
			contentPanel.add(lblDireccion, gbc_lblDireccion);
		}
		{
			comboBoxActor = new JComboBox<ActorDTO>();
			GridBagConstraints gbc_comboBox = new GridBagConstraints();
			gbc_comboBox.insets = new Insets(0, 0, 5, 5);
			gbc_comboBox.fill = GridBagConstraints.HORIZONTAL;
			gbc_comboBox.gridx = 1;
			gbc_comboBox.gridy = 1;
			contentPanel.add(comboBoxActor, gbc_comboBox);
		}
		{
			JLabel lblLocalidad = new JLabel("Role:");
			GridBagConstraints gbc_lblLocalidad = new GridBagConstraints();
			gbc_lblLocalidad.anchor = GridBagConstraints.EAST;
			gbc_lblLocalidad.insets = new Insets(0, 0, 5, 5);
			gbc_lblLocalidad.gridx = 0;
			gbc_lblLocalidad.gridy = 2;
			contentPanel.add(lblLocalidad, gbc_lblLocalidad);
		}
		comboBoxPapel = new JComboBox<String>();
		GridBagConstraints gbc_comboBoxAsesor = new GridBagConstraints();
		gbc_comboBoxAsesor.insets = new Insets(0, 0, 5, 5);
		gbc_comboBoxAsesor.fill = GridBagConstraints.HORIZONTAL;
		gbc_comboBoxAsesor.gridx = 1;
		gbc_comboBoxAsesor.gridy = 2;
		contentPanel.add(comboBoxPapel, gbc_comboBoxAsesor);
		comboBoxPapel.addItem("Main");
		comboBoxPapel.addItem("Secondary");
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
				List<PeliculaDTO> listaPeliculas = control.buscarPeliculas();
				for(PeliculaDTO pelicula:listaPeliculas){
					comboBoxPelicula.addItem(pelicula);
				}
				List<ActorDTO> listaActores = control.buscarActores();
				for(ActorDTO actor:listaActores){
					comboBoxActor.addItem(actor);
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
						crearActuacionMenuItemActionPerformed(arg0);
					}
				});
				crearButton.setActionCommand("OK");
				buttonPane.add(crearButton);
				getRootPane().setDefaultButton(crearButton);
			}
			{
				JButton cancelarButton = new JButton("Close");
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

	private void crearActuacionMenuItemActionPerformed(ActionEvent arg0){
		

		PeliculaDTO pelicula = (PeliculaDTO) comboBoxPelicula.getSelectedItem();
		ActorDTO actor = (ActorDTO) comboBoxActor.getSelectedItem();
					
		try{
			ActuaDTO actua= new ActuaDTO(actor.getCod_act(), pelicula.getCod_peli(), (String)comboBoxPapel.getSelectedItem());
			control.crearActuacion(actua);
			JOptionPane.showMessageDialog(this,"Performance created.", "Movie",JOptionPane.INFORMATION_MESSAGE);
			  
			 // do_this_windowClosing(new WindowEvent(getOwner(), WindowEvent.WINDOW_CLOSING));
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
