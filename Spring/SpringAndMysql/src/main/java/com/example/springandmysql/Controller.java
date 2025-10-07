package com.example.springandmysql;

import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;

import javax.swing.text.html.parser.Entity;

import org.springframework.beans.factory.annotation.Autowired;
import com.example.springandmysql.EntityFile;
import com.example.springandmysql.ServiceFile;

@RestController
public class Controller {

	private final ServiceFile service;
	
	@Autowired
	public Controller(ServiceFile serv) {
		this.service = serv;
	}
	
	@GetMapping("/")
	public String home(Model model) {
		model.addAttribute("message", "MVC model Index");
		return "index";
	}
	
	@GetMapping("/All")
	public String getAllEntities(Model model) {
		model.addAttribute("Entities", service.findAllEntity());
		return "entityList";
	}
	
	@GetMapping("/One")
	public String createEntityForm(Model model) {
		model.addAttribute("Entity", new EntityFile());
		return "createEntity";
	}
	
	@PostMapping("/save")
	public String saveEntity(@ModelAttribute EntityFile entity) {
		service.saveEntity(entity);
		return "redirect:/All";
	}
	
	
}
