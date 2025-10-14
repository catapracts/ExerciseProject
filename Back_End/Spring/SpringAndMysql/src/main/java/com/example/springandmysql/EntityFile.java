package com.example.springandmysql;

import lombok.Getter;
import lombok.Setter;
import lombok.NoArgsConstructor;

import javax.persistence.Id;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;

@Entity
@Getter
@Setter
@NoArgsConstructor
public class EntityFile {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)  // ID 자동 증가
    private Long id;
    private String username;
    private String email;
    private String password;
    
}
