import java.sql.*;

public class DbInsert{

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
            String query ="Insert into Student values(8,'Div',620)";
            request = Db.createStatement();
            result = request.executeUpdate(query);
          
	    query ="Insert into Student values(9,'Niki',545)";
            result = request.executeUpdate(query);
           
	    query="Select * from student";
            r=request.executeQuery(query);
           // request.close();
        }
       catch(SQLException E)
       {
           System.out.println(E);
       }

       String num;
       String name;
       String marks;
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
               marks=r.getString(3);
               prnrw=num+" "+name+" "+marks;
               System.out.println(prnrw);
           }while(r.next());
       }
      request.close();
      Db.close();
    }

}