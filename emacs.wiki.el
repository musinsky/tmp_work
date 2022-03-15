;; Emacs customize
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(mediawiki-site-alist
   '(("UEFI" "http://alice.saske.sk/mediawiki/" "musinsky" "Sestra1" nil "UEFI")))
 '(mediawiki-site-default "UEFI")
 '(package-selected-packages '(mediawiki markdown-mode)))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(require 'mediawiki)
(setq url-user-agent "FOO")


(defun yyr-mediawiki-browser-edit/create-page (page &optional site)
  "Edit a page in browser, asks for page name (sitename also if needed)"
  (interactive "sPage name (words): ")
  (let* ((site (mediawiki-prompt-for-site))
         (url (mediawiki-site-extract site 1))
         (index "index.php?title=")
         (et "&action=edit"))
    (funcall 'browse-url
             (message "%s%s%s%s"
                      url index (mediawiki-translate-pagename page) et))))

