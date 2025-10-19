package com.example.springandmysql.Security;

import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.AfterReturning;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class LoggingAspect {
	@Before("execution(* com.example.springandmysql.ServiceFile.*(..))")
	public void logBeforeService(JoinPoint joinPoint) {
		System.out.println("Before use : " + joinPoint.getSignature().toShortString());
	}
	
	@AfterReturning(pointcut = "execution(* com.example.springandmysql.ServiceFile.*(..))", returning = "result")
	public void logAfterService(JoinPoint joinPoint, Object result)  {
		System.out.println("After use : " + joinPoint.getSignature().toShortString() + " result : " + result);
	}
}

