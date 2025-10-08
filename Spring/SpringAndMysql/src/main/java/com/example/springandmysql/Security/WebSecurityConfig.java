package com.example.springandmysql.Security;

import java.beans.Customizer;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.web.SecurityFilterChain;

@Configuration
@EnableWebSecurity
public class WebSecurityConfig {

	@Bean
	public SecurityFilterChain filterChanin(HttpSecurity http) throws Exception {
		http
			.csrf().disable()
			.authorizeHttpRequests((authz) -> authz
					.requestMatchers("/public/**").permitAll()
					.anyRequest().authenticated()
			)
			.formerLogin(Customizer.withDefaults());
		return http.build();
	}
	
}
