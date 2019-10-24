/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package p;

import java.io.IOException;
import javax.servlet.jsp.tagext.SimpleTagSupport;
import java.util.Date;
import java.text.SimpleDateFormat;
import javax.servlet.jsp.JspWriter;

/**
 *
 * @author acer
 */
public class q9 extends SimpleTagSupport{
    
    
    
     public void doTag() throws IOException
    {
         Date d=new Date();
          SimpleDateFormat date;
     date = new SimpleDateFormat("E yyyy.MM.dd 'at' hh:mm:ss a zzz");
        JspWriter out= getJspContext().getOut();
        out.println(date.format(d));
         }
   }          

