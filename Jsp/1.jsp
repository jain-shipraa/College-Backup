<%-- 
    Document   : 1
    Created on : Oct 21, 2016, 11:50:36 AM
    Author     : pc4
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="s" uri="/WEB-INF/tlds/newtag_library" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <h1>CUSTOMIZED TAGS</h1>
        <br>
        <P>This files shows the output of various customized tag of question 6,7,8</P>
        <h3>SUBSTRING OUTPUT:</h3>
         <s:substring input="DEEPTI" start="1" end="2"/>
         <br>
         <H3>REVERSE OUTPUT:</H3>
         <BR>
         <s:reverse input="NIKITA" />
         <br>
         <H3>TODAY OUTPUT:</H3>
         <BR>
         <s:today/>
         <BR>
         <s:choco texture="Chewy"/>
         <BR>
         <s:choco texture="Crunchy"/>
         <BR>
    </body>
</html>
