package com.example.springandmysql;

import org.springframework.ui.Model;
import org.springframework.validation.BindingResult;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import javax.validation.Valid;
import org.springframework.beans.factory.annotation.Autowired;

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
	
	@GetMapping("/getAll")
	public String getAllEntities(Model model) {
		model.addAttribute("Entities", service.findAllEntity());
		return "entityList";
	}
	
	@GetMapping("/getOne")
	public String createEntityForm(Model model) {
		model.addAttribute("Entity", new EntityFile());
		return "createEntity";
	}
	
	@PostMapping("/save")
	public String saveEntity(@ModelAttribute @Valid DataForm dto,
							 BindingResult bindingResult, Model model) {
		
		if(bindingResult.hasErrors()) {
			model.addAttribute("DataForm", dto);
			return "createData";
		}
		
		EntityFile ent = new EntityFile();
		ent.setUsername(dto.getName());
		ent.setEmail(dto.getEmail());
		ent.setPassword(dto.getPassword());
		service.saveEntity(ent);
		return "redirect:/All";
	}
	
	@PostMapping("/delete")
	public String deleteEntity(Long id) {
		service.deleteData(id);
		return "redirect:/";
	}
	
}
