.PHONY: clean All

All:
	@echo "----------Building project:[ ppong - Debug ]----------"
	@cd "ppong" && "$(MAKE)" -f  "ppong.mk"
clean:
	@echo "----------Cleaning project:[ ppong - Debug ]----------"
	@cd "ppong" && "$(MAKE)" -f  "ppong.mk" clean
