<%-- 
    Document   : newjsp
    Created on : Oct 10, 2017, 9:38:38 AM
    Author     : acer
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
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
        using scriptlets<br>
<%  int x=Integer.parseInt(request.getParameter("rows"));
    
    for(int i=1;i<=x;i++)
    {
        for(int j=1;j<=i;j++)
        {
            out.print(j+"  ");
        }%>
        <br>
   <% }
%>
 Using for each<br>
    <c:forEach var="i" begin="1" end="${param.rows}">
        <c:forEach var="j" begin="1" end="${i}">
            <c:out value="${j}">  
            </c:out>
        </c:forEach>
            <br>
    </c:forEach>
     </body>
</html>

    
    
