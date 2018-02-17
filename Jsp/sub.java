/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package q7;

import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

/**
 *
 * @author pc4
 */
public class sub extends SimpleTagSupport {
    private String input;
    private int start;
    private int end;
    
    public void setInput(String i)
    {
        this.input=i;
    }
    
    public void setStart(int s)
    {
        this.start=s;
    }
    
    public void setEnd(int e)
    {
        this.end=e;
    }
    
    public void doTag() throws IOException
    {
        JspWriter Out=getJspContext().getOut();
        Out.println(input.substring(start,end));
        
    }
}
