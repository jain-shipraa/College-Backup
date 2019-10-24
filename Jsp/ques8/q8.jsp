<%-- 
    Document   : q7
    Created on : Oct 24, 2017, 11:26:19 AM
    Author     : acer
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@taglib uri="/WEB-INF/q7" prefix="str" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    <str:reverse input="${param.t1}"/>
    </body>
</html>
