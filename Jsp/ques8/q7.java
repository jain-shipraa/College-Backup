/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package p;

import java.io.IOException;
import javax.servlet.jsp.JspWriter;
import javax.servlet.jsp.tagext.SimpleTagSupport;

/**
 *
 * @author acer
 */
public class q7 extends SimpleTagSupport {
    String input;
    public void setInput(String n)
    {
        input=n;
    }
    
    public void doTag() throws IOException
    {
         
        JspWriter out= getJspContext().getOut();
         input=new StringBuilder(input).reverse().toString();
         out.println(input);
         }
    }          
