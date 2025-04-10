<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@ page language="java" %>
<!DOCTYPE html>
<html>
<head>
<title>JSP Example</title>
</head>
<body>
<h1>This is the code within the JSP tags to display the server time</h1>
<%--IThis is the JSP content that displays the server time by using the Date class
of the java.utilpackagel--%>
<% java.util.Date now=new java.util.Date(); %>
<H2><%= now %></H2>
</body>
</html>