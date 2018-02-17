/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package q7;

import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;


public class Q6 extends SimpleTagSupport {
   private String NAME;
   public void setNAME(String n)
   {this.NAME=n;
    
    }
    public void doTag() throws IOException
    {
        JspWriter Out=getJspContext().getOut();
        
        Out.println("Hello "+NAME);
    }
            
    
}