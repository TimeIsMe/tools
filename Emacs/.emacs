(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(package-selected-packages '(ggtags)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )
(global-hl-line-mode 1)
(add-hook 'c-mode-common-hook
	  (lambda ()
	    (when (derived-mode-p 'c-mode 'c++-mode 'java-mode)
	      (ggtags-mode 1))))
(setq inhibit-splash-screen t)
(add-to-list 'default-frame-alist '(fullscreen . maximized))
(put 'set-goal-column 'disabled nil)
(show-paren-mode 1)
(setq-default show-paren-style 'expression)
(setq c-default-style "linux"
      c-basic-offset 4)
