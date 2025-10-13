package com.example.springandmysql;

import java.util.List;
import java.util.Optional;

import org.springframework.beans.factory.annotation.Autowired;

public class Dao {

	@Autowired
	private Repository repo;
	
	public List<EntityFile> findAll() {
		return repo.findAll();
	}
	
	public Optional<EntityFile> findById(Long id) {
		return repo.findById(id);
	}
	
	public EntityFile save(EntityFile ent) {
		return repo.save(ent);
	}
	
	public void deleteById(Long id) {
		repo.deleteById(id);
	}
}
