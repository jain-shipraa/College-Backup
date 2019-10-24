/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package q9;

import java.io.IOException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author acer
 */
public class substring extends SimpleTagSupport{
      String input; int start,end;
    public void setStart(int n)
    {
        start=n;
    }
      public void setEnd(int n)
    {
        end=n;
    } 
      public void setInput(String n)
    {
        input=n;
    }
    public void doTag() throws IOException
    {
         
        JspWriter out= getJspContext().getOut();
        out.println(input.substring(start,end));
             
         }
    }          
    

