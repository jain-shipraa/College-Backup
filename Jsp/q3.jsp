<%-- 
    Document   : q3
    Created on : Nov 8, 2016, 7:40:41 AM
    Author     : ANKITA
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c"  uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
    </head>
    <body>
        <h2>validating form using bean</h2>
        
        <form  method="post">
            <table>
                <tr><td>Name:</td><td><input type="text"></td></tr>
            </table>
            
        </form>
        <jsp:useBean class="q7.valbean" id="userInfo">
            <jsp:setProperty name="userInfo" property="*"/>
            </jsp:useBean>
        <c:out value="${userInfo.name}"/>
    </body>
</html>

