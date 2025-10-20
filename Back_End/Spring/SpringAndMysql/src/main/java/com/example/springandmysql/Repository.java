package com.example.springandmysql;

import java.util.Optional;

import org.springframework.data.jpa.repository.JpaRepository;

public interface Repository extends JpaRepository<EntityFile, Long> {
	
	Optional<EntityFile> findByUsername(String username);

}
