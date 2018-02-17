

import java.sql.*;

public class DbProc {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        // TODO code application logic here
       Connection Db;
       Class.forName("oracle.jdbc.driver.OracleDriver");
       Db=DriverManager.getConnection("jdbc:oracle:thin:u111/u0111@192.168.54.10:1521:orcl");
       String result=null;
       

       try
       {
          String query =" {CALL countrows(?)}";
          CallableStatement cs = Db.prepareCall(query);
          cs.registerOutParameter(1,java.sql.Types.VARCHAR);
          cs.execute();
          result= cs.getString(1);
          cs.close();
           // request.close();
        }
       catch(SQLException E)
       {
           System.out.println(E);
       }
   
       
        System.out.println("Result:"+ result);
        Db.close();
    }

}