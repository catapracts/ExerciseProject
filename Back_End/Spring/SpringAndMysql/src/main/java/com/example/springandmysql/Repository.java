package com.example.springandmysql;

import com.example.springandmysql.EntityFile;
import org.springframework.data.jpa.repository.JpaRepository;

public interface Repository extends JpaRepository<EntityFile, Long> {

}
