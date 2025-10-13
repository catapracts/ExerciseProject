package com.example.springandmysql;

import com.example.springandmysql.EntityFile;
import com.example.springandmysql.Repository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Optional;

@Service
public class ServiceFile {
	private final Repository repository;
	
	@Autowired
	public ServiceFile(Repository repo) {
		this.repository = repo;
	}
	
	public List<EntityFile> findAllEntity() {
		return repository.findAll();
	}
	
	public Optional<EntityFile> findEntityById(Long id) {
		return repository.findById(id);
	}
	
	public EntityFile saveEntity(EntityFile file) {
		return repository.save(file);
	}
	
	
}
