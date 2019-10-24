<%-- 
    Document   : substring
    Created on : Oct 31, 2017, 9:27:02 AM
    Author     : acer
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%@taglib uri="/WEB-INF/substring" prefix="sub" %>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <sub:substring input="${param.input}" start="${param.start}" end="${param.end}"/>
    </body>
</html>
