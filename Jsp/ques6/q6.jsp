<%-- 
    Document   : q6
    Created on : Oct 24, 2017, 9:45:51 AM
    Author     : acer
--%>


<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>

<%@taglib uri="/WEB-INF/q6" prefix="a" %>


<html>
    
<head>
        
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        
<title>JSP Page</title>
    
</head>
    

<body>  
  
<a:hello name="${param.t1}"/>
  
<a:choco texture="${param.t2}"/>
    
</body>

</html>
