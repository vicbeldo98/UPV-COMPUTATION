package presentacion;
import logica.*;

import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JMenu;
import javax.swing.JOptionPane;





import excepciones.DAOExcepcion;

import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.Dimension;

public class CineApp {

	private JFrame frmGestionCine;
	private JMenuBar menuBar;
	private JMenu mnCine;
	private JMenuItem mntmConectar;
	private JMenuItem mntmDesconectar;
	private JMenuItem mntmSalir;
	

	private Controlador control;
	private JMenu mnPeliculas;
	private JMenuItem mntmCrearPelicula;
	private JMenuItem mntmAnyadirActuacion;
	private JMenuItem mntmListarPeliculas;
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					CineApp window = new CineApp();
					
					window.frmGestionCine.setVisible(true);
					//window.frmGestionCine.setLocationRelativeTo(null);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public CineApp() {
		initialize();
		initDominio();
				
	}
	

	public void initDominio(){
		try{
			control=new Controlador();
			
		}catch (Exception e){
			System.out.println(e.getMessage());
		}
	}
	
	

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frmGestionCine = new JFrame();
		frmGestionCine.setTitle("Cinema Database");
		frmGestionCine.setResizable(false);
		frmGestionCine.setMinimumSize(new Dimension(800, 500));
		frmGestionCine.setBounds(100, 100, 542, 343);
		frmGestionCine.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		menuBar = new JMenuBar();
		frmGestionCine.setJMenuBar(menuBar);
		
		mnCine = new JMenu("File");
		menuBar.add(mnCine);
		
		mntmConectar = new JMenuItem("Connect");
		mntmConectar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ConnectarSistema connect = new ConnectarSistema(control);
				int resultado = connect.showDialog();
				if (resultado==JOptionPane.OK_OPTION){
					mnPeliculas.setEnabled(true);
					mntmConectar.setEnabled(false);
					mntmDesconectar.setEnabled(true);
				}
				
			}
		});
		mnCine.add(mntmConectar);
		
		
		mntmDesconectar = new JMenuItem("Disconnect");
		mntmDesconectar.setEnabled(false);
		mntmDesconectar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				try {
					control.desconectar();				
					mnPeliculas.setEnabled(false);
					mntmConectar.setEnabled(true);
					mntmDesconectar.setEnabled(false);
				} catch (DAOExcepcion e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
		});
		mnCine.add(mntmDesconectar);
		
		mntmSalir = new JMenuItem("Exit");
		mntmSalir.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		mnCine.add(mntmSalir);
		
		mnPeliculas = new JMenu("Movies");
		mnPeliculas.setEnabled(false);
		menuBar.add(mnPeliculas);
		
		mntmCrearPelicula = new JMenuItem("Create Movie");
		mntmCrearPelicula.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				do_mntmCrearPelicula_actionPerformed(arg0);
			}
		});
		mnPeliculas.add(mntmCrearPelicula);
		
		mntmAnyadirActuacion = new JMenuItem("New Performance (act)");
		mntmAnyadirActuacion.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				do_mntmAnyadirActuacion_actionPerformed(arg0);
			}
		});
		mnPeliculas.add(mntmAnyadirActuacion);
		
		mntmListarPeliculas = new JMenuItem("Movie List");
		mntmListarPeliculas.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				do_mntmListarPeliculas_actionPerformed(arg0);
			}
		});
		mnPeliculas.add(mntmListarPeliculas);

		initDominio();	
	}
	protected void do_mntmListarPeliculas_actionPerformed(ActionEvent arg0) {
		MostrarPeliculas listado;
		try {
			listado = new MostrarPeliculas(control);
			listado.showDialog();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	protected void do_mntmCrearPelicula_actionPerformed(ActionEvent arg0) {
		CrearPeliculaJDialog formulario;
		try {
			formulario = new CrearPeliculaJDialog(control);
			formulario.showDialog();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	protected void do_mntmAnyadirActuacion_actionPerformed(ActionEvent arg0) {
		CrearActuacionJDialog formulario;
		try {
			formulario = new CrearActuacionJDialog(control);
			formulario.showDialog();
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
