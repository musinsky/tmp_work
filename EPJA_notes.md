Template
--------
* Info 2020-05, poznamka: evidentne to robili asi "taliani", cisty chaos a bordel.

* Na stranke [EPJ](https://www.epj.org/) => LaTeX Macros => EPJ A stiahnut subor [svjour3-epj_a_c.zip](http://epj.org/images/stories/latex/svjour3-epj_a_c.zip). EPJ A a EPJ C pouzivaju identicky zip subor s templates. Z LaTeX pohladu medzi EPJ A a EPJ C **nie je rozdiel**.

* Subor `svjour3-epj_a_c.zip` (velkost 281.668 bytes) bol povodne vytvoreny asi len pre EPJ C. Vacsina suborov je z roku 2010-2011, vratane suboru `template-epjc.tex` z roku 2011. V roku 2019 bol dodany jediny subor `template-epja.tex`.

* Pre LaTeX potrebne len subory
  * **`svjour3.cls`** LaTeX document class for Springer journals (SVJour3 version 3.3)
  * **`svglov3.clo`** SVJour3 global class option file
  * **`svepjc3.clo`** SVJour3 epjc3 class option file
  * `spphys.bst` BibTeX bibliographic style file (len v pripade pouzivania BibTeX)

* Template subory `template-epja.tex` a `template-epjc.tex` su z pohladu LaTeX identicke. Jediny rozdiel, epja pridava nejake bla, bla ohladom computer program description. Obidva template subory `template-epj{a,c}.tex` vyuzivaju SVJour3 class option file `svepjc3.clo`, na rozdiel od vseobecneho, globalneho template suboru `template.tex`. Podstatne "hodnotnejsi" template je vsak epjc sample subor **`svjourn3-epjc.tex`**, v ktorom je viac info ako v template suboroch.

* Na [Manuscript central EPJ A](https://mc.manuscriptcentral.com/epja) stranke je medzi zdrojmi uvadzany aj Submission Template subor [EPJA_templ.zip](https://mc.manuscriptcentral.com/societyimages/epja/EPJA_templ.zip) (rovnaky subor je aj pre EPJ C). Tento subor je vsak nepouzitelny, zastaraly (obsahuje, okrem ineho, class SVJour 1.11 z roku 2003).
