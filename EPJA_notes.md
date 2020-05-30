European Physical Journal A
---------------------------
* Info 2020-05.

* Instrukcie pre autorov, vseobecne informacie ohladom pisanie clanku, na stranke [EPJ A](https://epja.epj.org/) => *Instructions for Authors* stiahnut subor [instructions_epja.pdf](http://www.epj.org/images/stories/instructions/instructions_epja.pdf) (aktualne verzia z 2020-03-25).

## Template
* Na stranke [EPJ](https://www.epj.org/) => *LaTeX Macros* => *EPJ A* stiahnut subor [svjour3-epj_a_c.zip](http://epj.org/images/stories/latex/svjour3-epj_a_c.zip). EPJ A a EPJ C pouzivaju identicky zip subor s templates. Z LaTeX pohladu medzi EPJ A a EPJ C **nie je rozdiel**.

* Subor `svjour3-epj_a_c.zip` (velkost 281.668 bytes) bol povodne vytvoreny asi len pre EPJ C. Vacsina suborov je z roku 2010-2011, vratane suboru `template-epjc.tex` z roku 2011. V roku 2019 bol dodany jediny subor `template-epja.tex`.

* Pre pisanie clanku v EPJ A, resp. EPJ C v LaTeX su potrebne len subory
  * **`svjour3.cls`** LaTeX document class for Springer journals (SVJour3 version 3.3)
  * **`svglov3.clo`** SVJour3 global class option file
  * **`svepjc3.clo`** SVJour3 epjc3 class option file
  * `spphys.bst` BibTeX bibliographic style file (len v pripade pouzivania BibTeX)

* Template subory `template-epja.tex` a `template-epjc.tex` su z pohladu LaTeX identicke. Jediny rozdiel, epja pridava nejake bla, bla ohladom computer program description. Obidva template subory `template-epj{a,c}.tex` vyuzivaju doplnujuci SVJour3 class option file `svepjc3.clo`, na rozdiel od vseobecneho, globalneho template suboru `template.tex`. Podstatne "hodnotnejsi" template je vsak epjc sample subor **`svjourn3-epjc.tex`**, v ktorom je viac info ako v template suboroch.

## Doplnujuce info
* Na [Manuscript central EPJ A](https://mc.manuscriptcentral.com/epja) stranke je medzi zdrojmi pre autorov uvadzany aj *Submission Template* subor [EPJA_templ.zip](https://mc.manuscriptcentral.com/societyimages/epja/EPJA_templ.zip) (rovnaky subor je aj pre EPJ C). Tento subor je vsak nepouzitelny, zastaraly (obsahuje, okrem ineho, class SVJour version 1.11 z roku 2003).

* Na Overleaf strankach sa nachadza balik [A general template file for the LaTeX package SVJour3 for Springer journals](https://www.overleaf.com/latex/templates/a-general-template-file-for-the-latex-package-svjour3-for-springer-journals/pbbwqhxxvtbp) template pre EPJ (Springer) journals. Overleaf balik je balik stiahnuty zo [Springer stranky](http://static.springer.com/sgw/documents/468198/application/zip/LaTeX.zip), ktory v podstate obsahuje rovnake subory ako balik z EPJ A/C (subor `svjour3-epj_a_c.zip`), ale bez doplnujuceho `svepjc3.clo` epjc3 class option file. Tento balik obsahuje aj subor **`svjour3.cls`** class **version 3.2** z 2007-05-08. Rovnaky subor obsahuje aj balik z EPJ A/C, ale class **version 3.3** z 2010-11-25 ?! V skutocnosti su tieto subory **absolutne identicke**, jediny rozdiel je prave v cislovani verzii, resp. datume.

* Celkovo je situacia ohladom "kde co a ako pouzit" znacne neprehladna, niekedy su informacie priam protichodne. Ani v template (resp. sample) suboroch nie su jasne a striktne pravidla ako LaTeX-ovat. Ano, asi to robili "taliani".
