.PHONY: clean All

All:
	@echo "----------Building project:[ Battleship - Debug ]----------"
	@$(MAKE) -f  "Battleship.mk"
clean:
	@echo "----------Cleaning project:[ Battleship - Debug ]----------"
	@$(MAKE) -f  "Battleship.mk" clean
