
import java.sql.*;

public class DbUpdate {

    public static void main(String[] args) throws ClassNotFoundException, SQLException {
        // TODO code application logic here
       Connection Db;
       Class.forName("oracle.jdbc.driver.OracleDriver");
       Db=DriverManager.getConnection("jdbc:oracle:thin:u111/u0111@192.168.54.10:1521:orcl");
       Statement request=null;
       int result=0;
       ResultSet r=null;

       try
       {

          String query =" Update teacher set Name=CONCAT('DR.',NAME) where Name='RITA'";
          request = Db.createStatement();
          result = request.executeUpdate(query);
          query="Select * from teacher";
           r=request.executeQuery(query);
           // request.close();
        }
       catch(SQLException E)
       {
           System.out.println(E);
       }

       String num;
       String name;

       String prnrw;
       boolean records=r.next();
       System.out.println(records);
       if(!records)
       {
           System.out.println("No data");
       }
       else
       {
           do
           {
               num=r.getString(1);
               name=r.getString(2);
              
               prnrw=num+" "+name;
               System.out.println(prnrw);
           }while(r.next());
       }
      request.close();

      Db.close();
    }

}
