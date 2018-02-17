<%-- 
    Document   : greet
    Created on : Oct 26, 2016, 9:31:59 AM
    Author     : acer 12
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>

    <html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>GREETING PAGE</title>
    </head>
    <body>
        <h1>GREETING</h1>
        <jsp:useBean id="clock" class="java.util.Date"/>
        <c:choose>
            <c:when test="${clock.hours<12}">
                <h2>Good Morning <c:out value="${param.NAME}"/></h2>
            </c:when>
            <c:when test="${clock.hours<18}">
                <h2>Good Evening <c:out value="${param.NAME}"/> </h2>
            </c:when>    
            <c:otherwise>
                <h2>Good Night <c:out value="${param.NAME}"/></h2>
            </c:otherwise>
        </c:choose>
                
                Welcome!
    </body>
</html>
