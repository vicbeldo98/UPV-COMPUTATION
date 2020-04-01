package presentacion;

import java.awt.BorderLayout;
import java.awt.FlowLayout;

import java.util.ArrayList;
import java.util.Iterator;

import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.table.AbstractTableModel;
import javax.swing.JLabel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import comunicacion.ActorDTO;
import comunicacion.LibroDTO;
import comunicacion.PeliculaDTO;
import excepciones.DAOExcepcion;
import logica.Controlador;



import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class MostrarPeliculas extends JDialog {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private final JPanel contentPanel = new JPanel();
	private JScrollPane scrollPane;
	private JTable table;
	
	private Controlador controlador;
	
	private JScrollPane scrollPane_1;
	private JTable table_1;
	private JPanel panel;
	private JLabel lblPelculas;
	private JLabel lblNewLabel;
	private ArrayList<PeliculaDTO> lista;

//	/**
//	 * Launch the application.
//	 */
//	public static void main(String[] args) {
//		try {
//			MostrarParkingsArea dialog = new MostrarParkingsArea();
//			dialog.setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
//			dialog.setVisible(true);
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
//	}
	
	public int showDialog() {
		cargaPeliculas();
		setResizable(false);		
		setModal(true);
	    setVisible(true);
	    return 0;
	}
	/**
	 * Create the dialog.
	 * @throws Exception 
	 */
	public MostrarPeliculas(Controlador control) throws Exception {
		setTitle("Movies and Actors List");
		//gestionPlazas = new GestionPlazas(sistemaInfoCiudad.getPuntoInteres(), sistemaInfoCiudad.getDato());
		//tipoPlaza = tipo;
		controlador = control;
		
		setBounds(100, 100, 1225, 600);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		contentPanel.setLayout(null);
		
		scrollPane = new JScrollPane();
		scrollPane.setBounds(769, 51, 416, 462);
		contentPanel.add(scrollPane);
		
		table = new JTable(new ActorTableModel());
		table.getTableHeader().setResizingAllowed(false);
//		table.addMouseListener(new MouseAdapter() {
//			@Override
//			public void mouseClicked(MouseEvent arg0) {
//				do_table_mouseClicked(arg0);
//			}
//		});
		
		
		scrollPane.setViewportView(table);
		
		scrollPane_1 = new JScrollPane();
		scrollPane_1.setBounds(10, 50, 749, 463);
		contentPanel.add(scrollPane_1);
		
		table_1 = new JTable(new PeliculaTableModel());
		table_1.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent arg0) {
				do_table_mouseClicked(arg0);
			}
		});
		table_1.getTableHeader().setResizingAllowed(false);
		scrollPane_1.setViewportView(table_1);
		
		panel = new JPanel();
		scrollPane_1.setColumnHeaderView(panel);
		
		lblPelculas = new JLabel("Movies");
		lblPelculas.setBounds(10, 25, 126, 14);
		contentPanel.add(lblPelculas);
		
		lblNewLabel = new JLabel("Actors acting in the selected movie");
		lblNewLabel.setBounds(769, 26, 416, 14);
		contentPanel.add(lblNewLabel);
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				JButton okButton = new JButton("Show path");
				okButton.setVisible(false);
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						try {
							do_okButton_actionPerformed(arg0);
						} catch (Exception e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				});
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Close");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent arg0) {
						do_cancelButton_actionPerformed(arg0);
					}
				});
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
			}
		}

	}
	
	
	public void cargaPeliculas(){
		try{
			lista=	(ArrayList<PeliculaDTO>) controlador.buscarPeliculas();
			Iterator<PeliculaDTO> it= lista.iterator();
				
			PeliculaDTO pelicula;
			PeliculaTableModel model=(PeliculaTableModel) table_1.getModel();
			model.clear();
			while (it.hasNext()){
				pelicula=(PeliculaDTO) it.next();
				model.addRow(pelicula);
			}
			
			
		}catch (Exception e){
			JOptionPane.showMessageDialog(this,e.getMessage(),"ERROR", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	public void cargaActoresPelicula(String cod){
		try{
			ArrayList<ActorDTO> lista=	(ArrayList<ActorDTO>) controlador.buscarActoresPorCodPeli(cod);
			Iterator<ActorDTO> it= lista.iterator();
				
			ActorDTO actor;
			ActorTableModel model=(ActorTableModel) table.getModel();
			model.clear();
			
			while (it.hasNext()){
				actor=(ActorDTO) it.next();
				model.addRow(actor);
			}
			//cargaImagen(gestionPlazas.getUrlMapa());
			
		}catch (Exception e){
			JOptionPane.showMessageDialog(this,e.getMessage(),"ERROR", JOptionPane.ERROR_MESSAGE);
		}
	}
	
	
	//******************************************************************************************
	// Clase interna para del Modelo de la tabla
	//******************************************************************************************
	    class PeliculaTableModel extends AbstractTableModel {
	        /**
			 * 
			 */
			private static final long serialVersionUID = 1L;

			private String[] columnNames = { "Movie_code", "Title","Year", "Length", "Director", "Based on", "Book author"};
	        
	        private ArrayList<PeliculaDTO> data=new ArrayList<PeliculaDTO>();
	        
	                
	        public int getColumnCount() {
	            return columnNames.length;
	        }
	 
	        public int getRowCount() {
	            return data.size();
	        }
	 
	        public String getColumnName(int col) {
	            return columnNames[col];
	        }
	 
	        public Object getValueAt(int row, int col) {
	        	
	        	PeliculaDTO pelicula =data.get(row);
	        	LibroDTO libro;
	        	String titulo, autor;
				try {
					if(pelicula.getCod_lib()==null || pelicula.getCod_lib().isEmpty())
					{
						titulo="";
						autor="";
					}
					else{
					libro = controlador.buscarLibroPorCod(pelicula.getCod_lib()); //Controlador.dameControlador()
					titulo = libro.getTitulo();
					autor = libro.getAutor();
					}
					
				} catch (DAOExcepcion e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
					titulo="";
					autor="";
				} 
	        	
	            switch(col){
	            case 0: return pelicula.getCod_peli();
	            case 1: return pelicula.getTitulo();
	            case 2: return pelicula.getAnyo();
	            case 3: return pelicula.getDuracion();
	            case 4: return pelicula.getDirector();
	            case 5: return titulo;
	            case 6: return autor;
	            default: return null;
	            }
	            
	        }
	        
	        public void clear(){       
	        	data.clear();
	        }
	        /*
	         * JTable uses this method to determine the default renderer/
	         * editor for each cell.  If we didn't implement this method,
	         * then the last column would contain text ("true"/"false"),
	         * rather than a check box.
	         */
	        public Class<? extends Object> getColumnClass(int c) {
	            return  getValueAt(0, c).getClass();
	        }
	 
	        public void addRow(PeliculaDTO row) {  
	            
	            data.add(row);  
	            this.fireTableDataChanged();  
	             
	            }  
	              
	            public void delRow(int row) {  
	              
	            data.remove(row);         
	            this.fireTableDataChanged();  
	              
	            }  
	    }
	    
	  //******************************************************************************************
		// Clase interna para del Modelo de la tabla
		//******************************************************************************************
		    class ActorTableModel extends AbstractTableModel {
		        /**
				 * 
				 */
				private static final long serialVersionUID = 1L;

				private String[] columnNames = { "Act_code", "Name", "Birth_date", "Country_name"};
		        
		        private ArrayList<ActorDTO> data=new ArrayList<ActorDTO>();
		        
		                
		        public int getColumnCount() {
		            return columnNames.length;
		        }
		 
		        public int getRowCount() {
		            return data.size();
		        }
		 
		        public String getColumnName(int col) {
		            return columnNames[col];
		        }
		 
		        public Object getValueAt(int row, int col) {
		        	ActorDTO actor =data.get(row);
		            switch(col){
		            case 0: return actor.getCod_act();
		            case 1: return actor.getNombre();
		            case 2: return actor.getFecha_nac();
		            case 3: return actor.getNom_pais();
		            default: return null;
		            }
		            
		        }
		        
		        public void clear(){       
		        	data.clear();
		        	this.fireTableDataChanged();  
		        }
		        /*
		         * JTable uses this method to determine the default renderer/
		         * editor for each cell.  If we didn't implement this method,
		         * then the last column would contain text ("true"/"false"),
		         * rather than a check box.
		         */
		        public Class<? extends Object> getColumnClass(int c) {
		            return  getValueAt(0, c).getClass();
		        }
		 
		        public void addRow(ActorDTO row) {  

		        	data.add(row);  
		        	this.fireTableDataChanged();  

		        }  

		        public void delRow(int row) {  

		        	data.remove(row);         
		        	this.fireTableDataChanged();  

		        }  
		    }
	protected void do_okButton_actionPerformed(ActionEvent arg0) throws Exception {
//		String urlPath = gestionPlazas.getUrlPath(table.getSelectedRow());
//		cargaImagen(urlPath);
	}
	
	protected void do_cancelButton_actionPerformed(ActionEvent arg0) {
		setVisible(false);
		dispose();
	}
	protected void do_table_mouseClicked(MouseEvent arg0) {
		if (table_1.getSelectedRow()!=-1) 
			cargaActoresPelicula(lista.get(table_1.getSelectedRow()).getCod_peli());
			//JOptionPane.showMessageDialog(this,lista.get(table_1.getSelectedRow()).getCod_peli(),"Mostrar", JOptionPane.ERROR_MESSAGE);
	}
}



