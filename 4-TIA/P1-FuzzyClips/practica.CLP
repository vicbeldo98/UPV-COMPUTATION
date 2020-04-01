(deftemplate carretera
	(slot id(type SYMBOL))
	(slot agrietamiento(type FLOAT))
	(slot temperaturaMin(type FLOAT))
	(slot temperaturaMax(type FLOAT))
	(slot densidad-trafico(type FLOAT))
	(slot necesidad-reasfaltado(default -1))
)


(deftemplate agrietamiento
0 100 porciento
(
	(ligero (10 1) (20 0))
	(medio (5 0) (25 1) (45 1) (55 0))
	(fuerte (50 0) (60 1))
)
)


(deftemplate temperatura
-10 90 grados
(
	(fria (5 1) (10 0))
	(moderada (-5 0) (15 1) (40 1) (50 0))
	(calida (35 0) (45 1))
)
)

(deftemplate densidad-trafico
0 300 veh-hora
(
	(baja (z 20 80))
	(alta (s 120 250))
)
)

(deftemplate necesidad-reasfaltado
0 100 unit
(
	(baja (z 10 25))
	(muyBaja very baja)
	(media (pi 15 60))
	(urgente (s 55 90))

)

)
(defrule urgencia-algomedia
	(and (agrietamiento fuerte) (temperatura moderada))
	=>
	(assert (necesidad-reasfaltado somewhat media))
)

(defrule urgencia-media
	(and (agrietamiento ligero) (temperatura fria))
	=>
	(assert (necesidad-reasfaltado media))
)

(defrule urgencia-media2
	(and (agrietamiento ligero) (temperatura calida))
	=>
	(assert (necesidad-reasfaltado media))
)

(defrule urgencia-muyBaja
	(and (agrietamiento ligero) (temperatura moderada))
	=>
	(assert (necesidad-reasfaltado very baja))
)

(defrule urgencia-urgente
	(and (agrietamiento medio) (temperatura fria))
	=>
	(assert (necesidad-reasfaltado urgente))
)

(defrule urgencia-baja
	(and (agrietamiento medio) (temperatura moderada))
	=>
	(assert (necesidad-reasfaltado baja))
)

(defrule urgencia-extremadamenteUrgente
	(and (agrietamiento fuerte) (temperatura calida))
	=>
	(assert (necesidad-reasfaltado extremely urgente))
)

(defrule urgencia-extremadamenteUrgente2
	(and (agrietamiento fuerte) (temperatura fria))
	=>
	(assert (necesidad-reasfaltado extremely urgente))
)


(defrule urgencia-muyUrgente
	(and (agrietamiento medio) (temperatura calida))
	=>
	(assert (necesidad-reasfaltado very urgente))
)


(defrule dTrafico-alta
	(densidad-trafico alta)
	=>
	(assert (necesidad-reasfaltado very urgente))
)

(defrule dTrafico-baja
	(densidad-trafico baja)
	=>
	(assert (necesidad-reasfaltado more-or-less baja))
)


(deffunction fuzzify (?fztemplate ?value ?delta)

        (bind ?low (get-u-from ?fztemplate))
        (bind ?hi  (get-u-to   ?fztemplate))

        (if (<= ?value ?low)
          then
            (assert-string
              (format nil "(%s (%g 1.0) (%g 0.0))" ?fztemplate ?low ?delta))
          else
            (if (>= ?value ?hi)
              then
                (assert-string
                   (format nil "(%s (%g 0.0) (%g 1.0))"
                               ?fztemplate (- ?hi ?delta) ?hi))
              else
                (assert-string
                   (format nil "(%s (%g 0.0) (%g 1.0) (%g 0.0))"
                               ?fztemplate (max ?low (- ?value ?delta))
                               ?value (min ?hi (+ ?value ?delta)) ))
            ))
)


(defrule defusificar
	(declare (salience -1))
	?f <- (necesidad-reasfaltado ?)
	=>
	(bind ?e (moment-defuzzify ?f))
	(bind ?e2 (maximum-defuzzify ?f))
	(printout t "La necesidad de reasfaltado con moment es "?e crlf)
	(printout t "La necesidad de reasfaltado con maxixum es "?e2 crlf)
	(halt)
)


(defrule fusificar
	?f <- (carretera (id ?)(agrietamiento ?agri)(temperaturaMin ?min)(temperaturaMax ?max)(densidad-trafico ?dTra))
	=>
	(fuzzify agrietamiento ?agri 0)
	(fuzzify temperatura ?min 0)
	(fuzzify temperatura ?max 0)
	(fuzzify densidad-trafico ?dTra 0)
)

(defrule leerconsola
	(initial-fact)
=>
	(printout t "Introduzca el nombre de la carretera: " crlf)
	(bind ?Rnombre (read))

	(printout t "Introduzca el nivel de agrietamiento: " crlf)
	(bind ?Ragrietamiento (read))
	
	(printout t "Introduzca la temperatura minima: " crlf)
	(bind ?Rmintemperatura (read))

	(printout t "Introduzca la temperatura maxima: " crlf)
	(bind ?Rmaxtemperatura (read))
	
	(printout t "Introduzca la densidad de trafico: " crlf)
	(bind ?dTrafico (read))
	(assert (carretera (id ?Rnombre)(agrietamiento ?Ragrietamiento)(temperaturaMin ?Rmintemperatura)(temperaturaMax ?Rmaxtemperatura)(densidad-trafico ?dTrafico)))
	
)

