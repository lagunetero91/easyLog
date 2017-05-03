# easyLog
EasyLog library for C++.

  Librería desarrollada en C++ para sistemas Windows. Está librería pretende hacer más sencillo el manejo de ficheros de Log en
las aplicaciones.

  **Constructor**
  
  >easyLog(string dirLog);   
    
     Este constructor permite especificar la carpeta donde se almacenarán los ficheros de Log generados.
  
  >easyLog();  
  
      Constructor por defecto. En caso de usarlo los ficheros de Log serán almacenados en la carpeta del 
    proyecto en el directorio "Logs".
                            
  >addInfoToLog(string logname, string info);
  
      Método que permite introducir información en un fichero de Log. Se debe especificar el nombre del fichero 
     y la información. En caso de que no exista el fichero de Log especificado este será creado.
     
      La información se irá escribiendo al final del fichero.
      
      **Ejemplo:**

      05/02/17|18:49:27->: Mensaje de prueba.
