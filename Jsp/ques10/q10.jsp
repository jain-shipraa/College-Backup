<%-- 
    Document   : q10
    Created on : Oct 31, 2017, 12:17:00 PM
    Author     : acer
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    <c:set var="name" value="${param.name}" scope="session"></c:set>
    <c:out value="hello!! ${param.name}">
    </c:out>
    <form name="f" action="product.jsp" method="POST">
          product name <input type="text" name="pname"/><br>
       
         <input type="submit">
        </form>
    </body>
</html>
