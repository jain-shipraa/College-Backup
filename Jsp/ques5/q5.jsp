<%-- 
    Document   : q5
    Created on : Oct 31, 2017, 12:35:37 PM
    
Author     : acer
--%>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib uri = "http://java.sun.com/jsp/jstl/functions" prefix = "fn" %>


<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>

<html>
    
<head>
        
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        
<title>JSP Page</title>
    
</head>
    
<body>
    
<c:set var="str" value="${param.string}">
    </c:set>
    
<c:set var="n" value="${fn:length(str)}"></c:set>
      
<c:set var="flag" value="1"/>
    
<c:choose>
        
  <c:when test="${param.r=='odd'}">
            
            
     <c:forEach var="i" begin="0" end="${fn:length(str)-1}" step="2">
        
         <c:set var="substr" value="${fn:substring(str,i,i+1)}"/>
            
           <c:choose>

             <c:when test="${fn:contains(substr,'a') || fn:contains(substr,'e') || fn:contains(substr,'i') ||  fn:contains(substr,'o') || fn:contains(substr,'u')}">
                
    
         </c:when>
          
             <c:otherwise >
                      
          
               <c:set var="flag" value="0"/>
 
             </c:otherwise>

           </c:choose>

     </c:forEach>

     <c:choose>
     
       <c:when test="${flag==1}">

         <c:out value= "You win!!!!"/>
         
         </c:when>
                      
       <c:otherwise>
               
         <c:out value="you loose"/>
                
       </c:otherwise> 
                                
             
     </c:choose>
       
  </c:when>
                 
  <c:otherwise>
                    
     <c:forEach var="i" begin="1" end="${fn:length(str)-1}" step="2">
            
       <c:set var="substr" value="${fn:substring(str,i,i+1)}"/>
          
       <c:choose>
               
          <c:when test="${fn:contains(substr,'a') || fn:contains(substr,'e') || fn:contains(substr,'i') ||  fn:contains(substr,'o') || fn:contains(substr,'u')}">
      
          </c:when>
                 
          <c:otherwise >
                      
                   
            <c:set var="flag" value="0"/>
             
          </c:otherwise>
          
      </c:choose>
           
    </c:forEach>
                
    <c:choose>
                      
       <c:when test="${flag==1}">
                        
           <c:out value= "You win!!!!"/>
                       
       </c:when>
                           
       <c:otherwise>
                              
           <c:out value="you loose"/>
                            
       </c:otherwise> 
                                
            
    </c:choose>
                  
  </c:otherwise>
                         
                        
   
</c:choose>
    
</body>}
7
</html>
