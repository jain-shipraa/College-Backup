
package q7;
import java.io.Serializable;
public class valbean implements Serializable {
    private String Name;
    private String Dob;
    private String Emailid;
    private int LNumber;
    private String Favouritefood;
    
    public valbean()
    {
            
    }
    
    public void setName(String s)
    {Name=s;}
    
    public void setDob(String s)
    {Dob=s;}
    
    public void setEmailid(String s)
    {Emailid=s;}
    
    public void setLNumber(int n)
    {LNumber=n;}
    
    public void setFavouritefood(String s)
    {Favouritefood=s;}
    
    public String getName()
    {return Name;}
    
    public String getDob()
    {return Dob;}
    
     public String getEmailid()
    {return Emailid;}
    
     public int getLNumber()
    {return LNumber;}
    
     public String getFavouritefood()
    {return Favouritefood;}
}
