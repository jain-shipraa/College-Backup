<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>

<%@taglib uri="/WEB-INF/tlds/newtag_library" prefix="xx" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
    
    
    <xx:Hello NAME="${param.NAME}"/>
    <br>
    
    <c:forEach begin="1" end="5" step="1" var="p">
        <c:forEach begin="1" end="${p}" step="1" var="q">
            <c:out value="${q}"/>
        </c:forEach>
        <br>
    </c:forEach>
    
    </body>
</html>
