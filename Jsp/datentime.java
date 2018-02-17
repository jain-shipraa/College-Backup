/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package q7;
import java.io.*;
import javax.servlet.jsp.*;
import javax.servlet.jsp.tagext.*;

import java.util.Date;

import java.text.DateFormat;
import java.text.SimpleDateFormat;

import java.util.Calendar;


public class datentime extends SimpleTagSupport {
    public void doTag() throws IOException
    {
        JspWriter Out=getJspContext().getOut();

        DateFormat dateformat=new SimpleDateFormat("yyyy/mm//dd HH:MM::SS");
        Date date=new Date();
        System.out.println(dateformat.format(date));
        
Calendar cal=Calendar.getInstance();
        Out.println(dateformat.format(cal.getTime()));
    }
            
    
}
