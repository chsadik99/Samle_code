# Samle_code
A question that I have published  on geeksforgeeks.

Given an array arr[] consisting of N integers and queries Q[][] of the form {L, R} where 0 ≤ L < R ≤ N – 1, the task for each query is to calculate the following equation :
KL | KL + 1 |…| KR – 1 
where Ki = (arr[i] ^ arr[i+1]) | (arr[i] ~ arr[i+1]), 
“~” represents binary XNOR, 
“^” represents binary XOR , 
“|” represents binary OR 
