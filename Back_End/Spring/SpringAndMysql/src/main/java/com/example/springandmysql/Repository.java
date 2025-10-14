package com.example.springandmysql;

import org.springframework.data.jpa.repository.JpaRepository;

public interface Repository extends JpaRepository<EntityFile, Long> {

}
