/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package q6;

import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author acer
 */
public class chococlass extends SimpleTagSupport{
      String texture;
    public void setTexture(String n)
    {
        texture=n;
    }
    
    public void doTag() throws IOException
    {
         
        JspWriter out= getJspContext().getOut();
         if(texture.equals("chewy"))
             out.println("FiveStar Barone");
         if(texture.equals("crunchy"))
             out.println("Munch kitkat");
             
         }
    }          
    

