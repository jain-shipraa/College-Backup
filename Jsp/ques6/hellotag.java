/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package q6;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.jsp.tagext.SimpleTagSupport;
import javax.servlet.jsp.JspWriter;  

/**
 *
 * @author acer
 */
public class hellotag extends SimpleTagSupport
{ 
     String name1;
    public void setName(String n)
    {
        name1=n;
    }
    
    public void doTag()
    {
         
        JspWriter out= getJspContext().getOut();
         try {
             out.println("hello "+name1);
         } catch (IOException ex) {
             Logger.getLogger(hellotag.class.getName()).log(Level.SEVERE, null, ex);
         }
    }          
}
