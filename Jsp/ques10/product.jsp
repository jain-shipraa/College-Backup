<%-- 
    Document   : product
    Created on : Oct 31, 2017, 12:24:02 PM
    Author     : acer
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    <c:out value="hello!! ${name}"></c:out>
<br/>   
    <c:out value="you have ordered ${param.pname}"></c:out>
    </body>
</html>
