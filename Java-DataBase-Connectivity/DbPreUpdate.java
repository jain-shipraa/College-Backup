
import java.sql.*;

public class DbPreUpdate{

    public static void main(String[] args) throws ClassNotFoundException, SQLException {

       Connection Db;
       Class.forName("oracle.jdbc.driver.OracleDriver");
       Db=DriverManager.getConnection("jdbc:oracle:thin:u111/u0111@192.168.54.10:1521:orcl");
       Statement request=null;
       int result=0;
       ResultSet r1=null;
       ResultSet r2=null;

       try
       {
          String query =" Update teacher set Name=CONCAT('DR.',NAME) where Name=? ";
          
	  PreparedStatement ps=Db.prepareStatement(query);
          ps.setString(1,"GITA");
          r1=ps.executeQuery();
          ps.close();
          
	  request = Db.createStatement();
          query="Select * from teacher";
          r2=request.executeQuery(query);
        }
       catch(SQLException E)
       {
           System.out.println(E);
       }

       String num;
       String name;
       String prnrw;

       boolean records=r2.next();
       System.out.println(records);
       if(!records)
       {
           System.out.println("No data");
       }
       else
       {
           do
           {
               num=r2.getString(1);
               name=r2.getString(2);

               prnrw=num+" "+name;
               System.out.println(prnrw);
           }while(r2.next());
       }
       request.close();
       Db.close();
    }

}
