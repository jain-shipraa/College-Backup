<%-- 
    Document   : current
    Created on : Nov 1, 2017, 10:54:21 AM
    Author     : acer
--%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <jsp:useBean id="clock" class="java.util.Date"/>
        <c:choose>
            <c:when test="${clock.hours<12}">
              good morning  <c:out value="${param.t1}" />
            </c:when>
            <c:when test="${clock.hours<16}">
              good afternon  <c:out value="${param.t1}" />
            </c:when>
            <c:when test="${clock.hours<18}">
              good evening  <c:out value="${param.t1}"/>
            </c:when>
            <c:otherwise>
              good night  <c:out value="${param.t1}"/>
            </c:otherwise>
            </c:choose>
    </body>
</html>
