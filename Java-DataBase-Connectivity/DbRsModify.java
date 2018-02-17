
import java.sql.*;

public class DbRsModify
{

    public static void main(String[] args) throws ClassNotFoundException, SQLException
    {
       Connection Db;
       Class.forName("oracle.jdbc.driver.OracleDriver");
       Db=DriverManager.getConnection("jdbc:oracle:thin:u111/u0111@192.168.54.10:1521:orcl");
       Statement request=null;
       int result=0;
       ResultSet r=null;

       try
       {
          String query =" Select * from Student where name='Ayush'";
          request = Db.createStatement(ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
          r = request.executeQuery(query);
	  r.moveToInsertRow();
 	  r.updateString("FIRSTNAME", "Andreas");
  	  r.updateString("LASTNAME", "Korneliussen");
          r.updateInt("WORKDEPT", 123);
          r.insertRow();
  	  r.moveToCurrentRow();          
       }
       catch(SQLException E)
       {
           System.out.println(E);
       }

       String num;
       String name;
       String n2;

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
               n2=r.getString(3);

               prnrw=num+" "+name+" "+n2;
               System.out.println(prnrw);
           }while(r.next());

        
       }
      request.close();

      Db.close();
    }

}
