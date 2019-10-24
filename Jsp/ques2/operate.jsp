<%-- 
    Document   : operate
    Created on : Oct 12, 2017, 10:59:23 AM
    Author     : acer
--%>

<%@page language="java" contentType="text/html" pageEncoding="UTF-8"%>
<% 
    int num1=Integer.parseInt(request.getParameter("txt1"));
    int num2=Integer.parseInt(request.getParameter("txt2"));
    String value=request.getParameter("radio1");
    if(value.equals("addition"))
        out.println("Sum of numbers  "+(num1+num2));
    else if(value.equals("subtraction"))
        out.println("Difference of numbers  "+(num1-num2));
    else 
        out.println("Multiplication of numbers  "+(num1*num2));
  
    %>