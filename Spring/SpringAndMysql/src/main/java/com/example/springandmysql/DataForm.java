package com.example.springandmysql;

import javax.validation.constraints.Email;
import javax.validation.constraints.NotBlank;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@Data
public class DataForm {
	
	private Long id;

	@NotBlank(message = "Please enter your name")
	private String name;
	
	@NotBlank(message = "Please enter your email")
	@Email(message = "This isn't correct email form")
	private String email;
	
	@NotBlank(message = "Please enter your password")
	private String password;
	
}
