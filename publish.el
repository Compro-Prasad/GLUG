;; publish.el --- Publish org-mode presentations on Gitlab Pages
;; Author: Compro Prasad

;;; Commentary:
;; This script will convert the org-mode files to reveal js presentations.

;;; Code:

(require 'package)
(package-initialize)

(setf
 (alist-get "melpa" package-archives nil nil 'string=) "https://melpa.org/packages/"
 (alist-get "nongnu" package-archives nil nil 'string=) "https://elpa.nongnu.org/nongnu/")

(package-refresh-contents)

(when (not (package-installed-p 'org-contrib))
  (package-install 'org-contrib))
(when (not (package-installed-p 'htmlize))
  (package-install 'htmlize))
(when (not (package-installed-p 'org-re-reveal))
  (package-install 'org-re-reveal))

(require 'org)
(require 'org-re-reveal)

;; setting to nil, avoids "Author: x" at the bottom
(setq user-full-name nil)

(setq org-export-with-section-numbers nil
      org-export-with-smart-quotes t
      org-export-with-toc nil)

(setq org-html-divs '((preamble "header" "top")
                      (content "main" "content")
                      (postamble "footer" "postamble"))
      org-html-container-element "section"
      org-html-metadata-timestamp-format "%Y-%m-%d"
      org-html-checkbox-type 'html
      org-html-html5-fancy t
      org-html-validation-link nil
      org-html-doctype "html5")

(dolist (filename (file-expand-wildcards "workshops/*/README.org"))
  (with-current-buffer (find-file-noselect filename)
    (message "Exporting %s" filename)
    (org-re-reveal-export-to-html)
    (message "Export complete")
    (let ((original-html "README.html")
          (index-html "index.html"))
      (if (file-exists-p original-html)
          (progn
            (message "%s file created. Renaming to %s." original-html index-html)
            (rename-file original-html index-html t))
        (message "%s file wasn't created. Renaming wont be done." original-html)))))

(provide 'publish)
;;; publish.el ends here
