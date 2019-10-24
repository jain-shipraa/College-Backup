<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<%@page contentType="text/html" pageEncoding="UTF-8"%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
    
"http://www.w3.org/TR/html4/loose.dtd">



<html>
    
<head>
        
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        
<title>QUESTION 3 JSP</title>
    
</head>

    
<body>
        
<FORM action="try.jsp" method="post">
            
<input type="hidden" name="submitted" value="true"/>
             
<c:if test="${param.submitted && empty param.n1}">please enter your name</c:if> 
               

Name : <input type="text" name="n1" value="${param.n1}"/><BR>
               
             
<c:if test="${param.submitted && empty param.n2}">please enter your birth date</c:if>
               

Birth date : <input type="text" name="n2" value="${param.n2}"/><BR>
               
            
<c:if test="${param.submitted && empty param.n3}">please enter your email address</c:if>
               

Email address : <input type="text" name="n3" value="${param.n3}"/><BR>
               
            
<c:if test="${param.submitted &&  param.n4!= 'm' && param.n4!= 'f'}">please select a valid  gender</c:if>
               

Gender : 
                 
<c:choose>
                 
  <c:when test="${param.n4== 'f'}">
                     
    <input type="radio" name="n4" value="m"/>male<BR>
                   
    <input type="radio" name="n4" value="f" checked/>female<BR>
                  
  </c:when>
                     
  <c:otherwise>
                        
    <input type="radio" name="n4" value="m" checked />male<BR>
                        
    <input type="radio" name="n4" value="f"/>female<BR>
                      
  </c:otherwise>       
                
</c:choose>
               
               
<c:if test="${param.submitted &&  param.n5<1 || param.n5>100}">please enter lucky number between 1 and 100</c:if>
               

Lucky number : <input type="text" name="n5" value="${param.n5}"/><BR>
                
<c:forEach items="${paramValues.n6}" var="cur">
              
 <c:choose>
                  
  <c:when test="${cur=='z'}"> 
                      
    <c:set var="pizzaSelected" value='true'/>
                  
  </c:when>

                     
  <c:when test="${cur=='p'}"> 
                      
    <c:set var="pastaSelected" value='true'/>
                      
                  
  </c:when>     
                  
  <c:when test="${cur=='c'}"> 
                      
    <c:set var="burgerSelected" value='true'/>
                  
  </c:when>
 
                  
  <c:otherwise>
                      
    <c:set var="invalidselection" value="true"/>
                      
  </c:otherwise>   
                  
 </c:choose>

             
</c:forEach>

                       
              
                      

Favorite food : 
               
<input type="checkbox" name="n6" value="z" ${pizzaSelected? 'checked':''}/>PIZZA<BR>
               
<input type="checkbox" name="n6" value="p" ${pastaSelected? 'checked':''}/>PASTA<BR>
               
<input type="checkbox" name="n6" value="c" ${burgerSelected? 'checked':''}/>BURGER<BR>
               
<input type="submit" value="submit"/>
        
</FORM>                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
    </body>
</html>
